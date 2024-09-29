#include "ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation", 145, 137),
      _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &a)
    : AForm("Shrubbery Creation", 145, 137),
      _target(a._target) {
    *this = a;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &a) {
	if (this != &a)
	{
		AForm::operator=(a);
		_target = a._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {}

void ShrubberyCreationForm::printAsciiTree() const {
    std::cout << "                     ; ; ;\n";
    std::cout << "                   ;        ;  ;     ;;    ;\n";
    std::cout << "                ;                 ;         ;  ;\n";
    std::cout << "                                ;\n";
    std::cout << "                               ;                ;;\n";
    std::cout << "               ;          ;            ;              ;\n";
    std::cout << "               ;            ';,        ;               ;\n";
    std::cout << "               ;              'b      *\n";
    std::cout << "                ;              '$    ;;                ;;\n";
    std::cout << "               ;    ;           $:   ;:               ;\n";
    std::cout << "             ;;      ;  ;;      *;  @):        ;   ; ;\n";
    std::cout << "                          ;     :@,@):   ,;**:'   ;\n";
    std::cout << "              ;      ;,         :@@*: ;;**'      ;   ;\n";
    std::cout << "                       ';o;    ;:(@';@*\"'  ;\n";
    std::cout << "               ;  ;       'bq,;;:,@@*'   ,*      ;  ;\n";
    std::cout << "                          ,p$q8,:@)'  ;p*'      ;\n";
    std::cout << "                   ;     '  ; '@@Pp@@*'    ;  ;\n";
    std::cout << "                    ;  ; ;;    Y7'.'     ;  ;\n";
    std::cout << "                              :@):.\n";
    std::cout << "                             .:@:'.\n";
    std::cout << "                           .::(@:.\n";
}
