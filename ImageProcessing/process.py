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
  out2 = cv2.imread('processed_maze.png')

  print "Starting Point ",
  print (sr, sc)
  print "Ending Point ",
  print (er, ec)

  radius = 5
  cv2.circle(output, (sc,sr), radius, (0,0,255))
  cv2.circle(output, (ec,er), radius, (0,255,0))

  queue = []
  queue.append((sr,sc))
  dirs = [(1,0), (-1,0), (0,1), (0,-1)]

  width, height, t = output.shape

  path = {}
  print "Starting BFS"
  while queue:
    x,y = queue.pop(0)
    #print "Visiting",
    #print x,y
    cv2.circle(out2, (y,x), 1, (255,0,0))
    if (x,y) == (er, ec):
      print "Reached destination"
      break;
    for d in dirs:
      nx = x+d[0]
      ny = y+d[1]
      if (nx,ny) in path:
        print "Breaking because visited"
        continue
      if not (0 < nx < width and 0 < ny < height):
        print "Breaking because bounds"
        continue
      if tuple(output[nx,ny]) == (255,255,255):
        print "Breaking because white"
        continue
      else:
        print tuple(output[nx,ny]),
        print nx, ny
      queue.append((nx, ny))
      path[(nx, ny)] = (x,y)

  cv2.imwrite('1.jpg', out2)

  cx,cy = (er,ec)
  while not (cx,cy) == (sr,sc):
    cv2.circle(output, (cy,cx), 1, (255,0,0))
    cx,cy = path[(cx,cy)]

  cv2.imwrite('detected.jpg', output)

