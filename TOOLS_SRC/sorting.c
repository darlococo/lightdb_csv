#include "../TOOLS_API/sorting.h"
#include <string.h>

int id_compare(const void* a, const void* b) {
    // a = puntatore a puntatore di struct
    // cast a puntatore di cellulare sul valore del puntatore al puntatore
    // 0x50 = 0x20 || 0x20 = 0x10 || 0x10 = struct cellulare
    const cellulare * arg1 = (const cellulare *) *(const cellulare**) a;
    const cellulare * arg2 = (const cellulare *) *(const cellulare**) b;
    if (arg1->id > arg2->id) return -1;
    if (arg1->id < arg2->id) return 1;
    return 0;
}

int weight_compare(const void* a, const void* b) {
    const cellulare * arg1 = (const cellulare *) *(const cellulare**) a;
    const cellulare * arg2 = (const cellulare *) *(const cellulare**) b;
    if (arg1->weight > arg2->weight) return -1;
    if (arg1->weight < arg2->weight) return 1;
    return 0;
}

int ram_compare(const void* a, const void* b) {
    const cellulare * arg1 = (const cellulare *) *(const cellulare**) a;
    const cellulare * arg2 = (const cellulare *) *(const cellulare**) b;
    if (arg1->ram > arg2->ram) return -1;
    if (arg1->ram < arg2->ram) return 1;
    return 0;
}

int d_ppi_compare(const void* a, const void* b) {
    const cellulare * arg1 = (const cellulare *) *(const cellulare**) a;
    const cellulare * arg2 = (const cellulare *) *(const cellulare**) b;
    if (arg1->display_ppi > arg2->display_ppi) return -1;
    if (arg1->display_ppi < arg2->display_ppi) return 1;
    return 0;
}

int id_os_compare(const void* a, const void* b) {
    const cellulare * arg1 = (const cellulare *) *(const cellulare**) a;
    const cellulare * arg2 = (const cellulare *) *(const cellulare**) b;
    if (arg1->id_os > arg2->id_os) return -1;
    if (arg1->id_os < arg2->id_os) return 1;
    return 0;
}

int id_man_compare(const void* a, const void* b) {
    const cellulare * arg1 = (const cellulare *) *(const cellulare**) a;
    const cellulare * arg2 = (const cellulare *) *(const cellulare**) b;
    if (arg1->id_manufacturer > arg2->id_manufacturer) return -1;
    if (arg1->id_manufacturer < arg2->id_manufacturer) return 1;
    return 0;
}

int disp_size_compare(const void* a, const void* b) {
    const cellulare * arg1 = (const cellulare *) *(const cellulare**) a;
    const cellulare * arg2 = (const cellulare *) *(const cellulare**) b;
    if (arg1->display_size > arg2->display_size) return -1;
    if (arg1->display_size < arg2->display_size) return 1;
    return 0;
}

int disp_res_compare(const void* a, const void* b) {
    const cellulare * arg1 = (const cellulare *) *(const cellulare**) a;
    const cellulare * arg2 = (const cellulare *) *(const cellulare**) b;
    return strcmp(arg1->display_resolution, arg2->display_resolution);
}

int size_compare(const void* a, const void* b) {
    const cellulare * arg1 = (const cellulare *) *(const cellulare**) a;
    const cellulare * arg2 = (const cellulare *) *(const cellulare**) b;
    return strcmp(arg1->size, arg2->size);
}

int cpu_compare(const void* a, const void* b) {
    const cellulare * arg1 = (const cellulare *) *(const cellulare**) a;
    const cellulare * arg2 = (const cellulare *) *(const cellulare**) b;
    return strcmp(arg1->cpu, arg2->cpu);
}

int name_compare(const void* a, const void* b) {
    const cellulare * arg1 = (const cellulare *) *(const cellulare**) a;
    const cellulare * arg2 = (const cellulare *) *(const cellulare**) b;
    return strcmp(arg1->name, arg2->name);
}

int notes_compare(const void* a, const void* b) {
    const cellulare * arg1 = (const cellulare *) *(const cellulare**) a;
    const cellulare * arg2 = (const cellulare *) *(const cellulare**) b;
    return strcmp(arg1->notes, arg2->notes);
}

// Doesn't need a prototype
comparator_func get_comp_func(char * member) {
    for (size_t i = 0; fields[i].execute; i++) {
        if(!strcmp(member, fields[i].name))
            return fields[i].execute;
    }
    return NULL;
}

int cell_quick_sort(cellulare **main_table, size_t element_size, size_t nitems, char *member) {
    // TODO add reversed param && testing

    /// returns 0 if failed
    comparator_func c_f = get_comp_func(member);
    if (c_f) {
        qsort(main_table, nitems, element_size, c_f);
        size_t table_len = main_table_len(main_table);
        for (int i=0; i<table_len; i++) {
            main_table[i]->id = i+1;
        }
        return 1;
    }
    else
        return 0;
}
