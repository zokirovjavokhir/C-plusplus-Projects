#include "Directory.h"

#include <iomanip>
#include <sstream>

//DO NOT MODIFY THIS START
Entry* Directory::clone() const
{
    return new Directory(*this);
}
//DO NOT MODIFY THIS END

//Implement constructor, destructor, member functions of the Directory class.
//...
Directory::Directory(const std::string& name) {
    name_ = name;
    count_ = 0;

}   
Directory::Directory(const Directory& o) {
    name_ = o.name_;
    count_ = o.count_;
    for (int i = 0; i < maxcount_; i++) {
        entries_[i] = o.entries_[i];
    }
} 
Directory::~Directory() = default;
const std::string& Directory::name() const {
    return name_;
}
bool Directory::add(Entry* entry) {
    if (count_ == maxcount_) {
        std::cout << "the maximum number of resources that the one directory can hold is 8" << std::endl << std::endl;
        return false;
    }
    else {
        int index = -1;
        for (int i = 0; i < count_; i++) {
            if (entries_[i]->name() == entry->name())
                index = i;
        }
        if (index != -1) {
            std::cout << "directory or file with such name already exists" << std::endl << std::endl;
            return false;
        }
        else {
            entries_[count_] = entry;
            count_++;
            return true;
        } 
    }
}
void Directory::print(std::ostream& os, size_t indent) const {
    for (int i = 0; i < indent; i++)
        os << " ";
    os << "* " << name_ << std::endl;
    if (count_ > 0) {
        for (int i = 0; i < count_; i++) {
            entries_[i]->print(std::cout, indent + 3);
        }
    }
}
std::string Directory::content() const {
    std::string contents = "";
    for (int i = 0; i < count_; i++) {
        if (i == (count_ - 1)) 
            contents += entries_[i]->name();
        else
            contents += entries_[i]->name() + "\n";
    }
    return contents;
}
size_t Directory::count() const {
    return count_;
}
Entry* Directory::find(const std::string& name) {
    Entry* object = NULL;
    for (int i = 0; i < count_; i++) {
        if (entries_[i]->name() == name)
            object = entries_[i];
    }
    return object; 
}
Entry* Directory::remove(const std::string& name) {
    int index = -1;
    for (int i = 0; i < count_; i++) {
        if (entries_[i]->name() == name)
            index = i;
    }
    if (index != -1) {
        for (int j = index; j < count_ - 1; ++j)
            entries_[j] = entries_[j + 1];
        count_--;
    }
    return *entries_;
}