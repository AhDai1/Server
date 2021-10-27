#include"Util.h"
namespace Util
{
string ConstructPath(const string &path)
{
    string Webhome = "/home/ahdai/Server/http";
    if(path == "/"){
        return Webhome + "/index.html";
    }
    else{
        return Webhome + path;
    }
}
string GetExtent(const string &path)
{
    int i;
    for(i=path.size()-1;;i--){
        if(path[i] == '.')
            break;
    }
    return string(path.begin()+i+1,path.end());
}
void GetContentType(const string &tmpExtension, string &contentType)
{
    ifstream mineFile("mine.types");
    string line;
    while(getline(mineFile,line)){
        if(line[0] != '#'){
            stringstream lineStream(line);
            contentType.clear();
            lineStream>>contentType;
            vector<string> extensions;
            string extension;
            while(lineStream>>extension){
                extensions.push_back(extension);
            }
            for(int i=0;i<extensions.size();i++){
                if(tmpExtension == extensions[i]){
                    mineFile.close();
                    return ;
                }
            }
        }
    }
    contentType =  "text/html";
    mineFile.close();
}
string GetContent(const string &filename)
{
    ifstream fin(filename, ios::in| ios::binary);
    if(fin.fail()){
        return string("");
    }
    ostringstream oss;
    oss << fin.rdbuf();
    return string(oss.str());
}
}
