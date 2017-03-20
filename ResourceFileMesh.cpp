#include "Application.h"
#include "ModuleRenderer3D.h"
#include "ResourceFileMesh.h"
#include "ComponentMesh.h"
#include "MeshImporter.h"
#include "ModuleResourceManager.h"

ResourceFileMesh::ResourceFileMesh(ResourceFileType type, const std::string& file_path, unsigned int uuid) : ResourceFile(type, file_path, uuid)
{
}

ResourceFileMesh::~ResourceFileMesh()
{
	delete mesh;
}

Mesh * ResourceFileMesh::GetMesh() const
{
	return mesh;
}

void ResourceFileMesh::LoadInMemory()
{
	mesh = MeshImporter::Load(file_path.data());

	if (mesh)
	{
		bytes += sizeof(float) * 3 * mesh->num_vertices;
		bytes += sizeof(uint) * mesh->num_indices;
		bytes += sizeof(float) * 2 * mesh->num_uvs, mesh->uvs;
	}
	else
	{
		LOG("Couldn't load resource mesh: %s", file_path.data());
	}
}

void ResourceFileMesh::UnloadInMemory()
{
	MeshImporter::DeleteBuffers(mesh);
	App->resource_manager->RemoveResourceFromList(this);
}
