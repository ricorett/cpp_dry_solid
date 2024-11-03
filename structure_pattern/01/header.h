#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <algorithm>

class Text {
public:
    virtual void render(const std::string& data) const noexcept {
        std::cout << data;
    }
    virtual ~Text() noexcept = default;
};

class DecoratedText : public Text {
public:
    explicit DecoratedText(std::shared_ptr<Text> text) : text_(text) {}
    virtual ~DecoratedText() noexcept = default;

protected:
    std::shared_ptr<Text> text_;
};

class Reversed : public Text {
public:
    void render(const std::string& data) const noexcept override {
            std::string reversed = data;
            std::reverse(reversed.begin(), reversed.end());
            std::cout << reversed;
    }
};

class Link : public Text {
public:
    explicit Link(const std::string& url) : url_(url) {}
    void render(const std::string& data) const noexcept override {
            std::cout << "<a href=\"" << url_ << "\">" << data << "</a>";
    }

private:
    std::string url_;
};

class ItalicText : public DecoratedText {
public:
    explicit ItalicText(std::shared_ptr<Text> text) : DecoratedText(text) {}
    void render(const std::string& data) const noexcept override {
            std::cout << "<i>";
            text_->render(data);
            std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(std::shared_ptr<Text> text) : DecoratedText(text) {}
    void render(const std::string& data) const noexcept override {
            std::cout << "<b>";
            text_->render(data);
            std::cout << "</b>";
    }
};

class Paragraph : public DecoratedText {
public:
    explicit Paragraph(std::shared_ptr<Text> text) : DecoratedText(text) {}
    void render(const std::string& data) const noexcept override {
            std::cout << "<p>";
            text_->render(data);
            std::cout << "</p>";
    }
};