using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace lab11;

public class BubbleSorter : AbstractSorter
{
    public override void sort(ref int[] vector)
    {
        bool ok = false;
        while (!ok)
        {
            ok = true;
            for (int i = 0; i < vector.Length - 1; i++)
            {
                if (vector[i] > vector[i + 1])
                {
                    int temp = vector[i];
                    vector[i] = vector[i + 1];
                    vector[i + 1] = temp;
                    ok = false;
                }
            }
        }
    }
}