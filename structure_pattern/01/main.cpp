#include "header.h"

int main() {
    auto text_block = std::make_shared<ItalicText>(std::make_shared<BoldText>(std::make_shared<Text>()));
    text_block->render("Hello world");
    std::cout << std::endl;

    auto text_block1 = std::make_shared<Paragraph>(std::make_shared<Text>());
    text_block1->render("Hello world");
    std::cout << std::endl;

    auto text_block3 = std::make_shared<Reversed>();
    text_block3->render("Hello world");
    std::cout << std::endl;

    return 0;
}