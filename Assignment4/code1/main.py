from seam_carving import seam_carving
import cv2
import os


def main():
    input_path = os.path.join(os.path.dirname(__file__), 'image1.jpg')
    output_path = os.path.join(os.path.dirname(__file__), 'image1_result.jpg')

    image = cv2.imread(input_path)
    output = seam_carving(image,0.5)
    cv2.imwrite(output_path, output)


if __name__ == "__main__":
    main()


