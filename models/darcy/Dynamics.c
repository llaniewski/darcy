
CudaDeviceFunction float2 Color() {
  float2 ret;
  ret.x = pres(0,0);
  ret.y = 1;
  return ret;
}

CudaDeviceFunction real_t getP() {
    return pres(0,0);
}

CudaDeviceFunction void Init() {
    pres = Pressure;
    darcy = Darcy;
}

CudaDeviceFunction real_t CalcFlux(real_t p1, real_t d1, real_t p2, real_t d2) {
  // For p0 being pressure on edge:
  // flux = d1 * (p1-p0)/h = d2 * (p0-p2)/h
  // d1*p1-d1*p0 = d2*p0-d2*p2
  // d1*p1+d2*p2 = (d1+d2)*p0
  // p0 = (d1*p1+d2*p2)/(d1+d2)
  if (d1 + d2 == 0) return 0;
  real_t p0 = (d1*p1+d2*p2)/(d1+d2);
  return d1 * (p1-p0) * 2;
}

CudaDeviceFunction void Run() { 
  real_t resid = 0;
  real_t p = pres(0,0);
  real_t d = darcy(0,0);
  resid += CalcFlux(p,d,pres(1,0),darcy(1,0));
  resid += CalcFlux(p,d,pres(0,1),darcy(0,1));
  resid += CalcFlux(p,d,pres(-1,0),darcy(-1,0));
  resid += CalcFlux(p,d,pres(0,-1),darcy(0,-1));
  pres = p - Relaxation*resid;
  switch (NodeType & NODE_BOUNDARY) {
    case NODE_Dirichlet:
      pres = Pressure;
      break;
  }
}