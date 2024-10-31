#include <fstream>
#include <memory>
#include <string>
#include <stdexcept>
#include <iostream>

class Formatter
{
public:
    virtual ~Formatter() = default;
    virtual std::string format(const std::string& data) const = 0;
};

class HTMLFormatter : public Formatter
{
public:
    std::string format(const std::string& data) const override
    {
        return "<html>" + data + "</html>";
    }
};

class TextFormatter : public Formatter
{
public:
    std::string format(const std::string& data) const override
    {
        return data;
    }
};

class JSONFormatter : public Formatter
{
public:
    std::string format(const std::string& data) const override
    {
        return "{ \"data\": \"" + data + "\" }";
    }
};

class Data
{
public:
    explicit Data(std::string data)
        : data_(std::move(data)) {}

    const std::string& getData() const { return data_; }

private:
    std::string data_;
};

class Saver
{
public:
    explicit Saver(std::unique_ptr<Formatter> formatter)
        : formatter_(std::move(formatter)) {}

    void saveTo(std::ofstream& file, const Data& data) const
    {
        if (!file.is_open()) {
            throw std::ios_base::failure("Failed to open file.");
        }
        file << formatter_->format(data.getData());
    }

private:
    std::unique_ptr<Formatter> formatter_;
};
