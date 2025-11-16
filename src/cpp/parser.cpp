#include "../incl/parser.hpp"

using namespace Parser_ns;


Node::Node(const Node* l, const Node* r, const std::string& op) noexcept: 
op1(l), op2(r), op3(nullptr), type(Node::define_bin_op_type(op)) {}

Node::Node(const Node* oper, const std::string& op) noexcept:
op1(oper), op2(nullptr), op3(nullptr), type(Node::define_un_op_type(op)) {}

Node::Node(const std::string& n, const char v, const bool ic):
op1(nullptr), op2(nullptr), op3(nullptr), type(AST_Type::AST_LIT_CNST),
lc(n, v, ic) {}

Node::Node(const std::string& n, const short v, const bool ic):
op1(nullptr), op2(nullptr), op3(nullptr), type(AST_Type::AST_LIT_CNST),
lc(n, v, ic) {}

Node::Node(const std::string& n, const int v, const bool ic):
op1(nullptr), op2(nullptr), op3(nullptr), type(AST_Type::AST_LIT_CNST),
lc(n, v, ic) {}

Node::Node(const std::string& n, const long v, const bool ic):
op1(nullptr), op2(nullptr), op3(nullptr), type(AST_Type::AST_LIT_CNST),
lc(n, v, ic) {}

Node::Node(const std::string& n, const long long v, const bool ic):
op1(nullptr), op2(nullptr), op3(nullptr), type(AST_Type::AST_LIT_CNST),
lc(n, v, ic) {}


Node::Node(const std::string& n, const uc v, const bool ic):
op1(nullptr), op2(nullptr), op3(nullptr), type(AST_Type::AST_LIT_CNST),
lc(n, v, ic) {}

Node::Node(const std::string& n, const us v, const bool ic):
op1(nullptr), op2(nullptr), op3(nullptr), type(AST_Type::AST_LIT_CNST),
lc(n, v, ic) {}

Node::Node(const std::string& n, const ui v, const bool ic):
op1(nullptr), op2(nullptr), op3(nullptr), type(AST_Type::AST_LIT_CNST),
lc(n, v, ic) {}

Node::Node(const std::string& n, const ul v, const bool ic):
op1(nullptr), op2(nullptr), op3(nullptr), type(AST_Type::AST_LIT_CNST),
lc(n, v, ic) {}

Node::Node(const std::string& n, const ull v, const bool ic):
op1(nullptr), op2(nullptr), op3(nullptr), type(AST_Type::AST_LIT_CNST),
lc(n, v, ic) {}
    

Node::Node(const std::string& n, const float v, const bool ic):
op1(nullptr), op2(nullptr), op3(nullptr), type(AST_Type::AST_LIT_CNST),
lc(n, v, ic) {}

Node::Node(const std::string& n, const double v, const bool ic):
op1(nullptr), op2(nullptr), op3(nullptr), type(AST_Type::AST_LIT_CNST),
lc(n, v, ic) {}