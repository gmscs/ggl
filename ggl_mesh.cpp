#include "ggl.hpp"

namespace ggl {
    
int load_obj(const std::string &file, std::vector <ggl::vector3<float>> &Vertices, std::vector <ggl::vector3<float>> &Normals, std::vector <ggl::vector3<float>> &Texcoords, std::vector<ggl::vector3<float>> &Tangents, std::vector<unsigned int> &Indices) {
    Assimp::Importer importer;
    int total_vertices = 0;
	const aiScene* scene = importer.ReadFile(file, aiProcess_Triangulate);
	if(!scene) {
		std::cerr << "Failed to load scene." << "\n";
		return -1;
	}

    for(int m = 0; m < scene->mNumMeshes; m++) {
        const aiMesh* mesh = scene->mMeshes[m];
        total_vertices += mesh->mNumVertices;
	
        for(int i = 0; i < mesh->mNumVertices; i++) {
            const aiVector3D& mesh_vert = mesh->mVertices[i];
            Vertices.push_back(ggl::vector3<float>(mesh_vert.x,mesh_vert.y,mesh_vert.z));
            if(mesh->HasNormals()) {
                const aiVector3D& mesh_norm = mesh->mNormals[i];
                Normals.push_back(ggl::vector3<float>(mesh_norm.x,mesh_norm.y,mesh_norm.z));
            }
            if(mesh->HasTextureCoords(0)) {
                const aiVector3D& mesh_tex = mesh->mTextureCoords[0][i];
                Texcoords.push_back(ggl::vector3<float>(mesh_tex.x, mesh_tex.y, mesh_tex.z));
            }
            if(mesh->HasTangentsAndBitangents()) {
                const aiVector3D& mesh_tan = mesh->mTangents[i];
                Tangents.push_back(ggl::vector3<float>(mesh_tan.x, mesh_tan.y, mesh_tan.z));
            }
        }
        
        for(unsigned int i = 0; i < mesh->mNumFaces; i++) {
            const aiFace& face = mesh->mFaces[i];
            Indices.push_back(face.mIndices[0]);
            Indices.push_back(face.mIndices[1]);
            Indices.push_back(face.mIndices[2]);
        }
    }
	
	return total_vertices;
}

}//namespace_ggl
