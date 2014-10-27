import cv2

def findPoint(color, img):
  rows, cols, t = img.shape
  
  print rows, cols
  
  for r in range(rows):
    for c in range(cols):
      colors = img[r,c]
      if max(colors) == colors[color] and min(colors) != colors[color]:
        print "Found"
        print img[r,c]
        print (r,c)
        return r,c

  return None, None
          
if __name__ == "__main__":

  img = cv2.imread('maze.jpg')
  gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
  edges = cv2.Canny(gray,50,150,apertureSize = 3)

  cv2.imwrite('edges.jpg', edges)

  ret, thresh = cv2.threshold(gray, 0, 255, cv2.THRESH_BINARY_INV+cv2.THRESH_OTSU)

  cv2.imwrite('threshold.jpg', thresh)

  sr, sc = findPoint(2, cv2.imread('processed_maze.png'))
  er, ec = findPoint(1, cv2.imread('processed_maze.png'))

  output = cv2.imread('processed_maze.png')

  print "Starting Point ",
  print (sr, sc)
  print "Ending Point ",
  print (er, ec)

  radius = 5
  cv2.circle(output, (sc,sr), radius, (0,0,255))
  cv2.circle(output, (ec,er), radius, (0,255,0))

  cv2.imwrite('detected.jpg', output)

