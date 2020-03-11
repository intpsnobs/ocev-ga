class Freader {
private:
    std::fstream file;
public:
    void open(std::string fName) {
        try {
            this->file.open(fName, std::fstream::in | std::fstream::out);
        } catch(std::exception const& e) {
            std::cout << "Error on Freader_open " << e.what() << std::endl;
        }
    }

    std::pair<std::string,std::string> readLine() {
        if(file.is_open()) {
            std::string token;
            std::string value;
            std::string fullLine;
            std::getline(this->file, fullLine);
            std::getline(this->file, token, '=');
            std::getline(this->file, value);
            token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
            value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
            return {token,value};
        } else {
            return {"",""};
        }   
    }

    bool hasContent() {
        return !this->file.eof();
    }

};