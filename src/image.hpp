#ifndef IP_IMAGE_HPP_yyliu3
#define IP_IMAGE_HPP_yyliu3

#include <string>
#include <memory>

namespace IP
{
    class Image
    {
    public:
        /**
         * @brief Construct a new Image object
         * 
         */
        Image(const std::string&);

        /**
         * @brief Construct a new Image object
         * 
         */
        // Image(const char*);

        /**
         * @brief Construct a new Image object
         * 
         * @param w 
         * @param h 
         * @param ch 
         */
        Image(int w, int h, int ch);

        /**
         * @brief Construct a new Image object
         * 
         */
        Image(const Image& img) = delete;

        /**
         * @brief Construct a new Image object
         * 
         * @param img 
         */
        Image(Image&& img) = delete;
        
        /**
         * @brief Destroy the Image object
         * 
         */
        ~Image();

        /**
         * @brief 
         * 
         * @param filename 
         * @return true 
         * @return false 
         */
        bool read(const char* filename);

        /**
         * @brief 
         * 
         * @param filename 
         * @return true 
         * @return false 
         */
        bool write(const char* filename);

        // getters and setters for Implementation

        /**
         * @brief Get the Data object
         * 
         * @return uint8_t* 
         */
        uint8_t* getData() const;

        /**
         * @brief Set the Data object
         * 
         * @param index 
         * @param value 
         */
        void setData(uint8_t index, uint8_t value);

        /**
         * @brief Get the Size object
         * 
         * @return size_t 
         */
        size_t getSize() const;

        /**
         * @brief Set the Size object
         * 
         * @param size 
         */
        void setSize(size_t size);

        /**
         * @brief Get the Width object
         * 
         * @return int 
         */
        int getWidth() const;

        /**
         * @brief Set the Width object
         * 
         * @param width 
         */
        void setWidth(int width);

        /**
         * @brief Get the Height object
         * 
         * @return int 
         */
        int getHeight() const;

        /**
         * @brief Set the Height object
         * 
         * @param height 
         */
        void setHeight(int height);

        /**
         * @brief Get the Channels object
         * 
         * @return int 
         */
        int getChannels() const;

        /**
         * @brief Set the Channels object
         * 
         * @param channels 
         */
        void setChannels(int channels);

    private:
        struct Impl;
        std::unique_ptr<Impl> impl;
    };
}


#endif /* end of include guard : IP_IMAGE_HPP_yyliu3 */