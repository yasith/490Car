import cv2
cam = cv2.VideoCapture(0)
s, img = cam.read()

winName = "Movement Indicator"
cv2.namedWindow(winName, cv2.CV_WINDOW_AUTOSIZE)


def diffImg(t0, t1, t2):
    d1 = cv2.absdiff(t2, t1)
    d2 = cv2.absdiff(t1, t0)
    return cv2.bitwise_and(d1, d2)



while True:
  cv2.imshow(winName, img)

  #img = cv2.cvtColor(cam.read()[1], cv2.COLOR_RGB2GRAY)
  s, color = cam.read()

  gray = cv2.cvtColor(color,cv2.COLOR_BGR2GRAY)
  img = cv2.Canny(gray,50,150,apertureSize = 3)

  rows, cols, t = color.shape

  for r in range(rows):
      for c in range(cols):
          colors = color[r,c]
          if colors[1] > 100:
              cv2.circle(img, (r,c), 1, (0, 255, 0))

  key = cv2.waitKey(10)
  if key == 27:
    cv2.destroyWindow(winName)
    break
