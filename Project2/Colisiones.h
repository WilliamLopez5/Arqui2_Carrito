bool ColisionUltrasonico() {
  if (medirDistanciaSensorUltrasonico() > 0 && medirDistanciaSensorUltrasonico() < 15) {
        contadorObjetoEsquivados++;
    return true;
  }
  return false;
}
bool ColisionUltrasonicoR() {
  if (medirDistanciaSensorUltrasonicoR() > 0 && medirDistanciaSensorUltrasonicoR() < 15) {
        contadorObjetoEsquivados++;
    return true;
  }
  return false;
}
bool ColisionUltrasonicoL() {
  if (medirDistanciaSensorUltrasonicoR() > 0 && medirDistanciaSensorUltrasonicoR() < 15) {
        contadorObjetoEsquivados++;
    return true;
  }
  return false;
}


bool ColisionUltrasonicoR2() {
  if (medirDistanciaSensorUltrasonicoR() > 0 && medirDistanciaSensorUltrasonicoR() < 7) {
    return true;
  }
  return false;
}

bool ColisionUltrasonicoL2() {
  if (medirDistanciaSensorUltrasonicoL() > 0 && medirDistanciaSensorUltrasonicoL() < 7) {
    return true;
  }
  return false;
}



bool colisionFront() {
  if (ColisionUltrasonico()||detectarColorF()) {
    return true;
  }
  return false;
}

bool colisionRight() {
  if (ColisionUltrasonicoR()) {
    return true;
  }
  return false;
}

bool colisionLeft() {
  if (ColisionUltrasonicoL()) {
    return true;
  }
  return false;
}


bool colisionRight2() {
  if (ColisionUltrasonicoR2()) {
    return true;
  }
  return false;
}

bool colisionLeft2() {
  if (ColisionUltrasonicoL2()) {
    return true;
  }
  return false;
}
