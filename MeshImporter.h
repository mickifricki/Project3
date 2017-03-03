#ifndef __MESH_IMPORTER_H__
#define __MESH_IMPORTER_H__

#include <string>
#include <stack>

struct aiMesh;
struct aiNode;
struct aiScene;
struct Mesh;
class Data;

namespace MeshImporter
{
	//File is the final path of the imported file with the extension. Path is from the file is converted. Base path is the directory to save all generated files
	bool Import(const char* file, const char* path,const char* base_path, std::vector<unsigned int>& uuids);
	void ImportNode(aiNode* node, const aiScene* scene, GameObject* parent, std::string mesh_file_directory, std::vector<GameObject*>& objects_created, std::string folder_path, Data& root_data_node, std::vector<unsigned int>& uuids);
	bool ImportMesh(const aiMesh* mesh, const char* folder_path, std::string& output_name, unsigned int& uuid);
	bool Save(Mesh& mesh, const char* folder_path, std::string& output_name, unsigned int& uuid);
	
	Mesh* Load(const char* path);

	//Same as above but specifying the uuid
	bool ImportUUID(const char* file, const char* path, const char* base_path, std::stack<unsigned int>& uuids);
	void ImportNodeUUID(aiNode* node, const aiScene* scene, GameObject* parent, std::string mesh_file_directory, std::vector<GameObject*>& objects_created, std::string folder_path, Data& root_data_node, std::stack<unsigned int>& uuids);
	bool ImportMeshUUID(const aiMesh* mesh, const char* folder_path, std::string& output_name, unsigned int uuid);
	bool SaveUUID(Mesh& mesh, const char* folder_path, std::string& output_name, unsigned int uuid);

}

#endif // !__MESH_IMPORTER_H_
