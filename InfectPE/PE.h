#pragma once

namespace PE {
    struct PE_FILE {
        size_t size_ids{};
        size_t size_dos_stub{};
        size_t size_inh32{};
        size_t size_ish{};
        size_t size_sections{};
        IMAGE_DOS_HEADER ids;
        std::vector<char> MS_DOS_STUB;
        IMAGE_NT_HEADERS32 inh32;
        std::vector<IMAGE_SECTION_HEADER> ish;
        std::vector<std::shared_ptr<char>> Sections;
        void set_sizes(size_t, size_t, size_t, size_t, size_t);
    };

    std::tuple<bool, char*, std::streampos> OpenBinary(std::string filename);
    PE_FILE ParsePE(const char* PE);
    void WriteBinary(PE_FILE perfile, std::string file_name, size_t size);
}