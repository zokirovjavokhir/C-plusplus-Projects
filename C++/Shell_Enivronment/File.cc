#include "File.h"

#include <iomanip>

//DO NOT MODIFY START
File::~File() = default;

Entry* File::clone() const
{
    return new File(*this);
}
//DO NOT MODIFY END

File::File(const std::string& name, const std::string& content) {
    name_ = name;
    text_ = content;
}
File::File(const File& o) {
    name_ = o.name_;
    text_ = o.text_;
}
const std::string& File::name() const {
    return name_;
}
void File::print(std::ostream& os, size_t indent) const {
    if (indent != 0)
        indent--;
    for (int i = 0; i < indent; i++)
        os << " ";
    os << "* " << name_ << std::endl;
}
std::string File::content() const {
    return text_;
}
std::string File::content(const std::string& text) {
    text_ = text;
    return "Content updated!";
}