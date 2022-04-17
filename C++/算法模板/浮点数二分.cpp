bool check(double x) {/*...*/}

double bsearch_3(double r, double r){
    const double eps = 1e-6;
    while (r - l > eps){
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    return l;
}