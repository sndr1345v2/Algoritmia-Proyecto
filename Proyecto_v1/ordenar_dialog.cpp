#include "ordenar_dialog.h"
#include "ui_ordenar_dialog.h"

ordenar_dialog::ordenar_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ordenar_dialog)
{
    ui->setupUi(this);
}

ordenar_dialog::~ordenar_dialog()
{
    delete ui;
}


vector<Libro> menu_dialog::merge(const vector<Libro> &left, const vector<Libro> &right)
{

    vector<Libro> result;


    unsigned left_it = 0, right_it = 0;
    //string left_it =left[0].get_titulo();
    //string right_it= right[0].get_titulo();

    while(left_it < left.size() && right_it < right.size())
    {

        if(left[left_it] < right[right_it])
        {
            result.push_back(left[left_it]);
            left_it++;
        }
        else
        {
            result.push_back(right[right_it]);
            right_it++;
        }
    }


    while(left_it < left.size())
    {
        result.push_back(left[left_it]);
        left_it++;
    }

    while(right_it < right.size())
    {
        result.push_back(right[right_it]);
        right_it++;
    }

    return result;
}

vector<Libro> menu_dialog::merge_sort(vector<Libro> &vec)
{

    if(vec.size() == 1)
    {
        return vec;
    }


    std::vector<Libro>::iterator middle = vec.begin() + (vec.size() / 2);
    vector<Libro> left(vec.begin(), middle);
    vector<Libro> right(middle, vec.end());

    left = merge_sort(left);
    right = merge_sort(right);

    return merge(left, right);
}
