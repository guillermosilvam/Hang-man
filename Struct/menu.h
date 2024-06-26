#pragma once
#include <cstddef>
#include <functional>
#include <string_view>
#include <vector>

struct MenuFunction {
  std::string_view name;
  std::function<void()> function;
};

class Menu {
protected:
  std::string_view title{};
  std::string_view exitMessage{"GO BACK"};
  size_t totalOptions{};
  std::vector<MenuFunction> functions{};
  bool isUserQuitting(size_t selectedOption) const { return (selectedOption == totalOptions + 1); };
  bool isQuittingConfirmed() const;
  void printTitle() const;
  void print() const;
public:
  Menu (const Menu&) = delete;
  Menu& operator=(const Menu&) = delete; 
  Menu(const char* menuTitle, std::vector<MenuFunction> menufunctions) : title{menuTitle}, functions{menufunctions} { totalOptions = functions.size(); };
  void run() const;
};

class MainMenu : public Menu {
public:
  MainMenu(const char* title, std::vector<MenuFunction> functions) : Menu {title, functions} { Menu::exitMessage = "EXIT"; };
};