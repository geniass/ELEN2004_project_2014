double JtokWh(double joules)
{
    // 1 kWh = 3.6MJ
    return joules / (3.6e6);
}

double average(double total, int count)
{
    return total / count;
}
