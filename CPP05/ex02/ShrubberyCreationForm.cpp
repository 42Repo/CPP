#include "ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation", 145, 137),
      _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &a)
    : AForm("Shrubbery Creation", 145, 137),
      _target(a._target) {
    *this = a;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &a) {
    if (this != &a) {
        AForm::operator=(a);
        _target = a._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::beExecuted() const {
    std::ofstream outfile((_target + "_shrubbery").c_str());
    if (outfile.is_open()) {
        outfile << "                     ; ; ;\n";
        outfile << "                   ;        ;  ;     ;;    ;\n";
        outfile << "                ;                 ;         ;  ;\n";
        outfile << "                                ;\n";
        outfile << "                               ;                ;;\n";
        outfile << "               ;          ;            ;              ;\n";
        outfile << "               ;            ';,        ;               ;\n";
        outfile << "               ;              'b      *\n";
        outfile << "                ;              '$    ;;                ;;\n";
        outfile << "               ;    ;           $:   ;:               ;\n";
        outfile << "             ;;      ;  ;;      *;  @):        ;   ; ;\n";
        outfile << "                          ;     :@,@):   ,;**:'   ;\n";
        outfile << "              ;      ;,         :@@*: ;;**'      ;   ;\n";
        outfile << "                       ';o;    ;:(@';@*\"'  ;\n";
        outfile << "               ;  ;       'bq,;;:,@@*'   ,*      ;  ;\n";
        outfile << "                          ,p$q8,:@)'  ;p*'      ;\n";
        outfile << "                   ;     '  ; '@@Pp@@*'    ;  ;\n";
        outfile << "                    ;  ; ;;    Y7'.'     ;  ;\n";
        outfile << "                              :@):.\n";
        outfile << "                             .:@:'.\n";
        outfile << "                           .::(@:.\n";
        outfile.close();
    } else {
        std::cerr << "Erreur lors de la création du fichier." << std::endl;
    }
}
