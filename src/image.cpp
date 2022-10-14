#include <memory>
#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include <stdexcept>

#include "image.hpp"
#include "image_type.hpp"
#include <stb_image.h>
#include <stb_image_write.h>

struct IP::Image::Impl
{
    uint8_t *data = nullptr;
    size_t size = 0;
    int width;
    int height;
    int channels;
};

IP::Image::Image(const std::string &fileName)
    :   impl(std::make_unique<Impl>())
{
    const auto val = this->read(fileName.c_str());
    if(!val)
        throw std::runtime_error("There is an error reading file " + fileName);
    
    impl->size = impl->width * impl->height * impl->channels;
}

// IP::Image::Image(const char *fileName)
//     :   impl(std::make_unique<Impl>())
// {
// }

IP::Image::Image(int w, int h, int ch)
    : impl(std::make_unique<Impl>())
{
    impl->size = impl->width * impl->height * impl->channels;
    impl->data = new uint8_t[impl->size];
}

/* TODO: will after implement */
// IP::Image::Image(const Image& img)
// {
// }

// IP::Image::Image(Image&& img)
// {
// }

uint8_t* IP::Image::getData() const
{
    return impl->data;
}

void IP::Image::setData(uint8_t index, uint8_t value)
{
    impl->data[index] = value;
}

size_t IP::Image::getSize() const
{
    return impl->size;
}

IP::Image::~Image()
{
    stbi_image_free(impl->data);
}

bool IP::Image::read(const char* filename)
{
    impl-> data = stbi_load(filename, &impl->width, &impl->height, &impl->channels, 0);
    return impl->data != nullptr;
}

bool IP::Image::write(const char* filename)
{
    int checkSuccess = 0;
    IP::ImageType type = IP::Helper::getImageType(filename);

    switch (type) 
    {
        case IP::ImageType::PNG: {
            checkSuccess = stbi_write_png(
                filename, 
                impl->width,
                impl->height,
                impl->channels,
                impl->data,
                impl->width * impl->channels
            );
        }
        case IP::ImageType::BMP: {
            checkSuccess = stbi_write_bmp(
                filename,
                impl->width,
                impl->height,
                impl->channels,
                impl->data
            );
        }
        case IP::ImageType::JPG: {
            checkSuccess = stbi_write_jpg(
                filename, 
                impl->width,
                impl->height,
                impl->channels,
                impl->data,
                100
            );
        }
        case IP::ImageType::TGA: {
            checkSuccess = stbi_write_tga(
                filename, 
                impl->width,
                impl->height,
                impl->channels,
                impl->data
            );
        }
    }

    return checkSuccess != 0;
}