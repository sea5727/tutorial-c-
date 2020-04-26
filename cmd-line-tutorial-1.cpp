#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <boost/program_options.hpp>
using namespace boost;
using namespace boost::program_options;
using namespace std;

//https://www.boost.org/doc/libs/1_63_0/doc/html/program_options.html
int main(int argc, char **argv){
    printf("program start\n");

    options_description desc("Generic options");
    desc.add_options()
    ("help,h", "this is help")
    ("version,v", "this is version")
    ("all,a", "this is all")
    ("number,n", value<int>(), "this is number")
    ("import,i", value<string>(), "this is import")    
    ("include-path,I", value< vector<string> >()->multitoken(), "include path")
    ;
    options_description config("Configuration");
    config.add_options()
    ("input-file", value<vector<string>>(), "input file")
    ;

    options_description full;
    full.add(config).add(desc);

    variables_map vm;
    store(parse_command_line(argc, argv, full), vm);
    notify(vm);
    if(vm.count("help")){
        printf("Usage : cmd-line-tutorial-1 [option]\n");
        full.print(std::cout, 50);
        return 0;
    }

    try{
        store(parse_config_file("./config22.ini", desc), vm);
        notify(vm);
    }
    catch(reading_file &e){
        printf("%s", e.what());
    }
    
    

    if (vm.count("version")){
        printf("cmd : version\n");
    }
    if (vm.count("all")){
        printf("cmd : all\n");
    }
    if (vm.count("number")){
        printf("cmd : number : %d\n", vm["number"].as<int>());
    }
    if (vm.count("import")){
        printf("cmd : import : %s\n", vm["import"].as<string>().c_str());
    }
    if(vm.count("input-file")){
        printf("cmd : input file : \n");

    }
    if(vm.count("include-path")){
        for(auto const &i: vm["include-path"].as<vector<string>>()){
            printf("include-path:%s\n", i.c_str());
        }
        
    }

    printf("program end\n"); 

    return 0;
}
