using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab11;

public abstract class Factory
{
    public abstract Container createContainer(Strategy strategy);
}