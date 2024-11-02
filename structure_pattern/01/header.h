#pragma once
#include <string>
#include <iostream>

class Text {
public:
    virtual void render(const std::string& data) const {
        std::cout << data;
    }
};


class DecoratedText : public Text {
public:
    explicit DecoratedText(Text* text) : text_(text) {}
    Text* text_;
};

class Reversed : public Text {
public:
    void render(const std::string& data) const override {
        std::string reversed = data;
        std::reverse(reversed.begin(), reversed.end());
        std::cout << reversed;
    }
};

class Link : public Text {
public:
    Link(const std::string& url) : url_(url) {}

    void render(const std::string& data) const override {
        std::cout << "<a href=\"" << url_ << "\">" << data << "</a>";
    }
private:
    std::string url_;
};


class ItalicText : public DecoratedText {
public:
    explicit ItalicText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data)  const  {
        std::cout << "<i>";
        text_->render(data);
        std::cout << "</i>";
    }
};

class BoldText : public DecoratedText {
public:
    explicit BoldText(Text* text) : DecoratedText(text) {}
    void render(const std::string& data) const {
        std::cout << "<b>";
        text_->render(data);
        std::cout << "</b>";
    }
};

class Paragraph : public Text {
public:
    explicit Paragraph(Text* text) : text_(text) {}

    void render(const std::string& data) const override {
        std::cout << "<p>";
        text_->render(data);
        std::cout << "</p>";
    }

private:
    Text* text_;
};