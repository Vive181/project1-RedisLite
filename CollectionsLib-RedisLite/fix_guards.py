import os

files = [
    "include/dynamicArray.h",
    "include/doublylinkedList.h",
    "include/hashmap.h",
    "src/dynamicArray.cpp",
    "src/doublylinkedList.cpp",
    "src/hashmap.cpp",
    "src/linkedList.cpp"
]

for fpath in files:
    if not os.path.exists(fpath): continue
    with open(fpath, "r") as f:
        content = f.read()
    
    # Check if it has an unterminated #ifndef HASH_FUNCTION_CPP
    if "#ifndef HASH_FUNCTION_CPP" in content:
        # replace the macro name with a unique one based on filename
        base = os.path.basename(fpath).replace(".", "_").upper()
        content = content.replace("#ifndef HASH_FUNCTION_CPP", f"#ifndef {base}")
        content = content.replace("#define HASH_FUNCTION_CPP", f"#define {base}")
        
        # append #endif if it's missing
        if "#endif" not in content:
            content += f"\n#endif // {base}\n"
            
        with open(fpath, "w") as f:
            f.write(content)
