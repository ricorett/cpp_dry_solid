#include "header.h"

int main() {
    auto text_block = new ItalicText(new BoldText(new Text()));
    text_block->render("Hello world");
    std::cout << std::endl;

    auto text_block1 = new Paragraph(new Text());
    text_block1->render("Hello world");
    std::cout << std::endl;

    auto text_block3 = new Reversed();
    text_block3->render("Hello world");
    std::cout << std::endl;
}