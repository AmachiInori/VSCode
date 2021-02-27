# include "../src/AMI_Calcu.hpp"

double first(const std::vector<double> &a) {
    return a.front();
}

int main() {
    AmiCal::insert_function("sum_22", first);
    AmiCal::insert_macro("ad", "sum");
    std::cout << AmiCal::etoi("-1-1+sum_22(1234)");
    return 0;
}