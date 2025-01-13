using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab11;

public class MergeSorter : AbstractSorter
{
    public override void sort(ref int[] vector)
    {
        m_sort(ref vector, 0, vector.Length - 1);
    }

    private void m_sort(ref int[] arr, int l, int r)
    {
        if (l < r)
        {
            int m = (l + r) / 2;

            m_sort(ref arr, l, m);
            m_sort(ref arr, m + 1, r);

            merge(ref arr, l, m, r);
        }
    }

    private void merge(ref int[] arr, int l, int m, int r)
    {
        int n1 = m - l + 1;
        int n2 = r - m;

        int[] L = new int[n1];
        int[] R = new int[n2];
        for (int a = 0; a < n1; a++)
            L[a] = arr[l + a];
        for (int a = 0; a < n2; a++)
            R[a] = arr[m + 1 + a];

        int i = 0, j = 0;

        int k = l;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }

            k++;
        }

        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
}