import cv2
import numpy as np

image = cv2.imread("test2.jpg")
cv2.imshow("Original", image)
cv2.waitKey(0)

blurred_image = cv2.GaussianBlur(image, (11, 11), 0)

hsv_image = cv2.cvtColor(blurred_image, cv2.COLOR_BGR2HSV)

hsv_min = np.array((36, 25, 25), np.uint8)
hsv_max = np.array((70, 255, 255), np.uint8)

green_mask = cv2.inRange(hsv_image, hsv_min, hsv_max)
cv2.imshow("Green Mask", green_mask)
cv2.waitKey(0)

contours, hierarchy = cv2.findContours(green_mask.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

sorted_contours = sorted(contours, key=cv2.contourArea, reverse=True)

for cnt in sorted_contours:
  if cv2.contourArea(cnt) < 100:
    continue
  x, y, w, h = cv2.boundingRect(cnt)
  center_x = int(x + w / 2)
  center_y = int(y + h / 2)
  cv2.drawContours(image, [cnt], -1, (0, 255, 0), 3)
  cv2.circle(image, (center_x, center_y), 10, (0, 0, 255), -1)

cv2.imshow('Detected Green Objects & Centers', image)
cv2.waitKey(0)
cv2.destroyAllWindows()