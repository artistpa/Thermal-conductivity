void restoreF(const double* y,
              const double* lambda,
              const int size,
              const double step,
              const double timeStep,
              double* F) {
    const double coefficient = 1 / (2 * step * step);
    for (int i = 1; i < size - 1; ++i) {
        double lambdaPlusHalf = avg(lambda[i], lambda[i + 1]);
        double lambdaMinusHalf = avg(lambda[i], lambda[i - 1]);
        double temp = lambdaPlusHalf * (y[i + 1] - y[i]) - lambdaMinusHalf * (y[i] - y[i - 1]);
        F[i] = y[i] / timeStep + temp * coefficient;
    }
}
