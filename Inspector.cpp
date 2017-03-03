#include "Inspector.h"
#include "Application.h"
#include "Editor.h"

#include "GameObject.h"
#include "Component.h"

#include "ModuleGOManager.h"
#include "LayerSystem.h"

Inspector::Inspector()
{
	active = true;
	flags |= ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
}

Inspector::~Inspector()
{}

void Inspector::Draw()
{
	if (!active) return;

	ImGui::SetNextWindowSize(current_size);
	ImGui::SetNextWindowPos(current_position);

	ImGui::Begin("Inspector", &active, flags);

	ImGui::Text("Debug: "); ImGui::SameLine(); ImGui::Checkbox("##debug_inspector", &debug);
	ImGui::Separator();

	GameObject* selected_GO = nullptr;
	
	if (App->editor->selected.size() > 0)
		selected_GO = App->editor->selected.back();

	if (selected_GO)
	{

		//Active
		bool is_active = selected_GO->IsActive();
		if (ImGui::Checkbox("", &is_active))
		{
			selected_GO->SetActive(is_active);
		}

		//Name
		ImGui::SameLine();
		ImGui::InputText("###goname", selected_GO->name._Myptr(), selected_GO->name.capacity());

		//Static
		ImGui::SameLine();
		ImGui::Text("Static:");
		ImGui::SameLine();
		bool is_static = selected_GO->IsStatic();
		if (ImGui::Checkbox("###static_option", &is_static))
		{
			selected_GO->SetStatic(is_static);
		}

		if (selected_GO->IsPrefab())
		{
			ImGui::TextColored(ImVec4(0, 0.5f, 1, 1), "Prefab: ");
		}

		ImGui::Separator();
		App->go_manager->layer_system->DisplayLayerSelector(selected_GO->layer);

		if (debug)
		{
			ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(255, 255, 0, 255));
			ImGui::Text("UUID: %u", (int)selected_GO->GetUUID());
			ImGui::Text("Local UUID: %u", (int)selected_GO->local_uuid);
			ImGui::Text("Layer id: %i", selected_GO->layer);
			ImGui::PopStyleColor();
		}

		//Components
		const std::vector<Component*>* components = selected_GO->GetComponents();
		for (std::vector<Component*>::const_iterator component = (*components).begin(); component != (*components).end(); ++component)
		{
			(*component)->OnInspector(debug);
		}

		// Quick test for creating new components when clicking on no component
		ImGui::NewLine();
		if (ImGui::Button("Create component", ImVec2(current_size.x, 30)))
		{
			ImGui::OpenPopup("InspectorOptions");
		}

		if (ImGui::BeginPopup("InspectorOptions"))
		{
			if (ImGui::Selectable("Add Transform"))
			{
				selected_GO->AddComponent(C_TRANSFORM);
			}

			if (ImGui::Selectable("Add Mesh"))
			{
				selected_GO->AddComponent(C_MESH);
			}

			if (ImGui::Selectable("Add Material"))
			{
				selected_GO->AddComponent(C_MATERIAL);
			}

			if (ImGui::Selectable("Add Camera"))
			{
				selected_GO->AddComponent(C_CAMERA);
			}

			if (ImGui::Selectable("Add Light"))
			{
				selected_GO->AddComponent(C_LIGHT);
			}

			if (ImGui::Selectable("Add Audio"))
			{
				selected_GO->AddComponent(C_AUDIO);
			}

			ImGui::EndPopup();
		}
	}

	ImGui::End();
}
