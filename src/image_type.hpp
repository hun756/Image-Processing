#ifndef IP_IMAGE_TYPE_HPP_uk6wqb
#define IP_IMAGE_TYPE_HPP_uk6wqb

#include <stdexcept>
#include <string>

namespace IP
{
    enum class ImageType
    {
        PNG,
        JPG,
        BMP,
        TGA
    };

    namespace Helper
    {
        inline ImageType getImageType(const std::string& fileName)
        {
            auto posType = fileName.find_last_of(".");
            if (posType == std::string::npos) throw std::runtime_error("An error was encountered while finding the file extension.");
            auto foundedValue = fileName.substr(posType + 1);            
            if (foundedValue == "png") return ImageType::PNG;
            if (foundedValue == "jpg") return ImageType::JPG;
            if (foundedValue == "bmp") return ImageType::BMP;
            if (foundedValue == "tga") return ImageType::TGA;

            throw std::runtime_error("Invalid image file.");
        }
    }
}

#endif /* end of include guard : IP_IMAGE_TYPE_HPP_uk6wqb */