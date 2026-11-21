*This project has been created as part of the 42 curriculum by tfournie.*

<h1 align="center">⚙️ C++ Modules 00 to 09</h1>

<p align="center">
  <b>Ten modules to learn C++ from scratch: classes, memory, polymorphism, templates and the STL.</b>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/C++98-00599C?style=flat-square&logo=cplusplus&logoColor=white" alt="C++98">
  <img src="https://img.shields.io/badge/OOP-polymorphism-7c3aed?style=flat-square" alt="OOP">
  <img src="https://img.shields.io/badge/STL-containers_&_algorithms-2563eb?style=flat-square" alt="STL">
  <img src="https://img.shields.io/badge/42-Lyon-000000?style=flat-square&logo=42&logoColor=white" alt="42 Lyon">
</p>

---

## 📖 About

The C++ piscine of 42 is a series of 10 modules. Each one introduces a new part of the language through small, focused exercises. Everything is written in **C++98** and compiled with `-Wall -Wextra -Werror -std=c++98`, with no external library.

The goal is not only to make things work, but to understand **why**: object lifetime, who owns memory, what a virtual call costs, and how templates are instantiated.

## 🗺️ Modules

| Module | Topic | What I built |
|---|---|---|
| [**00**](Cpp00) | Namespaces, classes, I/O streams | `megaphone`, a **phone book** with formatted table output, and the `Account` class rebuilt from its header and a log file |
| [**01**](Cpp01) | Memory allocation, references, pointers to members | Stack vs heap `Zombie`s, a zombie horde, `HumanA` / `HumanB` with references vs pointers, a **`sed`-like** file replacer, and `Harl` with an array of pointers to member functions and a `switch` filter |
| [**02**](Cpp02) | Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form | A **fixed-point number class** (`Fixed`) with comparison, arithmetic and increment operators |
| [**03**](Cpp03) | Inheritance | `ClapTrap` → `ScavTrap` / `FragTrap` → `DiamondTrap`, the **diamond problem** solved with virtual inheritance |
| [**04**](Cpp04) | Subtype polymorphism, abstract classes, interfaces | `Animal` / `Dog` / `Cat` with virtual functions vs `WrongAnimal`, **deep copy** with a `Brain`, an abstract base class, and the start of the `AMateria` interface |
| [**05**](Cpp05) | Exceptions | A `Bureaucrat` that signs and executes `Form`s, with **custom exceptions** for out-of-range grades, three concrete forms and an `Intern` factory |
| [**06**](Cpp06) | C++ casts | A **scalar converter** (char / int / float / double, including `nan` and `inf`), a `Serializer` with `reinterpret_cast`, and **type identification with `dynamic_cast`** without `typeid` |
| [**07**](Cpp07) | Templates | Function templates (`swap`, `min`, `max`, `iter`) and a class template **`Array<T>`** with bounds checking |
| [**08**](Cpp08) | Templated containers, iterators, algorithms | `easyfind` on any container, a `Span` class using STL algorithms, and **`MutantStack`**: a `std::stack` that can be iterated |
| [**09**](Cpp09) | STL in practice | See below ⬇️ |

## 🏆 Module 09: the STL in real programs

### 💰 `btc`: Bitcoin exchange
Reads a CSV database of Bitcoin prices into a **`std::map`**, then evaluates an input file of `date | amount` lines. For each date, it finds the closest earlier price with `lower_bound`, and it validates every line: date format, real calendar dates, negative or too-large amounts.

### 🧮 `RPN`: Reverse Polish Notation calculator
Evaluates expressions such as `"8 9 * 9 - 9 - 9 - 4 - 1 +"` with a **`std::stack`**, and handles errors such as a bad token, a missing operand or a division by zero.

### 🔀 `PmergeMe`: Ford-Johnson merge-insertion sort
Sorts a sequence of positive integers with the **Ford-Johnson algorithm**, which is designed to minimize the number of comparisons:
1. Pair up the elements and sort each pair
2. Recursively sort the larger element of every pair
3. Insert the smaller elements with **binary search**, in the order given by the **Jacobsthal sequence**, so that every search runs on the smallest possible range

The same algorithm is implemented twice, with **`std::vector`** and with **`std::deque`**, and the program prints the time each container took.

## 🚀 Build and run

Every exercise has its own `Makefile`:

```bash
cd Cpp09/ex02
make
./PmergeMe 3 5 9 7 4
```

## 📚 What I learned

- **Orthodox Canonical Form**: default constructor, copy constructor, copy assignment operator and destructor, and when each one is called
- **RAII** and ownership: who allocates, who frees, and how to make deep copies right
- **Polymorphism**: virtual functions, virtual destructors, abstract classes and virtual inheritance
- **The 4 C++ casts** and when each one is appropriate
- **Templates** and the STL: containers, iterators and algorithms, and how to choose the right container for the job
