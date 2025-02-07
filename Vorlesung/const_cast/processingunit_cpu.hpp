template<class floating>
Timer CPU<floating>::createTimer() const
{
    return std::make_unique<OMP_Timer>();
}

template<class floating>
void CPU<floating>::display() const
{
    std::cout << "CPU" << std::endl;
    return;
}

template<class floating>
void CPU<floating>::xaxpy(const int n, const floating alpha, const floating * const x, const int incx, floating * const y, const int incy) const
{
    if constexpr(isFloat())
        cblas_saxpy(n, alpha, x, incx, y, incy);
    else if constexpr(isDouble())
        cblas_daxpy(n, alpha, x, incx, y, incy);

    return;
}

template<class floating>
floating CPU<floating>::xdot(const int n, const floating * const x, const int incx, const floating * const y, const int incy) const
{
    floating result = 0;
    if constexpr(isFloat())
        result = cblas_sdot(n, x, incx, y, incy);
    else if constexpr(isDouble())
        result = cblas_ddot(n, x, incx, y, incy);

    return result;
}

template<class floating>
void CPU<floating>::xgemm(const OperationType TransA, const OperationType TransB,
        const int M, const int N, const int K, const floating alpha, const floating * const A,
        const int lda, const floating * const B, const int ldb, const floating beta, floating * const C, const int ldc) const
{
    if constexpr(isFloat())
        cblas_sgemm(CblasColMajor, toInternalOperationBLAS.at(TransA), toInternalOperationBLAS.at(TransB),
                    M, N, K, alpha, A,
                    lda, B, ldb, beta, C, ldc);
    else if constexpr(isDouble())
        cblas_dgemm(CblasColMajor, toInternalOperationBLAS.at(TransA), toInternalOperationBLAS.at(TransB),
                    M, N, K, alpha, A,
                    lda, B, ldb, beta, C, ldc);
    return;
}

template<class floating>
void CPU<floating>::xgemv(const OperationType trans, const int m, const int n,
        const floating alpha, floating const * const a, const int lda, floating const * const x, const int incx,
        const floating beta, floating * const y, const int incy) const
{
    if constexpr(isFloat())
        cblas_sgemv(CblasColMajor, toInternalOperationBLAS.at(trans), m, n,
                    alpha, a, lda, x, incx,
                    beta, y, incy);
    else if constexpr(isDouble())
        cblas_dgemv(CblasColMajor, toInternalOperationBLAS.at(trans), m, n,
                    alpha, a, lda, x, incx,
                    beta, y, incy);

    return;
}


template<class floating>
void CPU<floating>::xgetrf(int * const m, int * const n, floating * const a, int * const lda,
        int * const ipiv, int * const info) const
{
    if constexpr(isFloat())
        sgetrf_(m, n, a, lda, ipiv, info);
    else if constexpr(isDouble())
        dgetrf_(m, n, a, lda, ipiv, info);

    return;
}

template<class floating>
void CPU<floating>::xgetrs(const OperationType trans, const int * const n, const int * const nrhs,
        const floating * const a, const int * const lda, const int * const ipiv,
        floating * const b, const int * const ldb, int * const info) const
{
    if constexpr(isFloat())
        sgetrs_(toInternalOperationLAPACK.at(trans), n, nrhs, a, lda, ipiv, b, ldb, info);
    else if constexpr(isDouble())
        //~ dgetrs_(const_cast<char*>(toInternalOperationLAPACK.at(trans)), n, nrhs, a, lda, ipiv, b, ldb, info);
		dgetrs_(const_cast<char*>(toInternalOperationLAPACK.at(trans)), const_cast<int*>(n), const_cast<int*>(nrhs), a, const_cast<int*>(lda), const_cast<int*>(ipiv), b, const_cast<int*>(ldb), info);
    return;
}

template<class floating>
void CPU<floating>::xscal(const int N, const floating alpha, floating * const X, const int incX) const
{
    if constexpr(isFloat())
        cblas_sscal(N, alpha, X, incX);
    else if constexpr(isDouble())
        cblas_dscal(N, alpha, X, incX);

    return;
}

template<class floating>
std::map<OperationType, CBLAS_TRANSPOSE> CPU<floating>::toInternalOperationBLAS = {
        {OperationType::Identical, CblasNoTrans},
        {OperationType::Transposed, CblasTrans},
        {OperationType::Hermitian, CblasConjTrans}
};

template<class floating>
std::map<OperationType, const char * const> CPU<floating>::toInternalOperationLAPACK = {
        {OperationType::Identical, "N"},
        {OperationType::Transposed, "T"},
        {OperationType::Hermitian, "C"}
};
