using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace lab11;

public interface Container
{
    Task remove();
    void add(Task task);
    int size();
    bool isEmpty();
}