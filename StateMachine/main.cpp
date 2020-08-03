#include <iostream>
#include <variant>
#include <vector>
#include <algorithm>
#include <iterator>
#include <filesystem>
#include <array>
#include <list>
//This project is dedicated to learning more about state-machines
//and how they can be efficiently implemented

//Using variant
//Things I am trying to figure out
//Counting how often the vending-machine was in a particular state

template<typename... T>
struct overloaded : T ... {
    using T::operator()...;
};
template<typename... Args> overloaded(Args... args)->overloaded<Args...>;

template<typename Variant, typename... Matchers>
auto match(Variant &&variant, Matchers &&... matchers) {
    return std::visit(overloaded{std::forward<Matchers>(matchers)...}, std::forward<Variant>(variant));
}

struct IdleState {
    uint32_t idle_counter{0u};
};
struct PickingState {
    uint32_t picking_counter{0u};
};

using State = std::variant<IdleState, PickingState>;


class VendingMachine {
private:
    State m_state;
    bool is_running{false};
public:

    void run();
};

void VendingMachine::run() {
    is_running = true;
    while (is_running) {
        m_state = match(m_state, [](IdleState &state) -> State {
            std::string input_message;
            std::getline(std::cin, input_message);
            if (input_message == "Geld abheben") {
                return PickingState{};
            }
            return state;
        }, [](PickingState &state) -> State {
            std::cout << "Wie viel geld moechten sie abheben ?" << std::endl;
            std::string input_message;
            std::getline(std::cin, input_message);
            if (input_message.find_first_not_of("0123456789") == std::string::npos) {
                std::cout << input_message << " wurde vom Knoto abgebucht" << std::endl;
                return IdleState{};
            }
            return state;
        });

    }
}

//There is a nice implementation of a state machine out there. I only need to find the
//motivation to finish that one :P

int main() {


    return 0;
}
