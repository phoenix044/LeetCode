public static boolean check(double x){
    return false;
}

public static double bsearch(double[] q, double l, double r){\
    const double eps = 1e-6;
    while(r - l > eps){
        double mid = (l + r) / 2;
        if check(mid) r = mid;
        else l = mid;
    }
    return l;
}