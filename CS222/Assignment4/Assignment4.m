image1 = imread("pout.tif");
subplot (3,2,1), imshow(image1)
subplot (3,2,2), imhist(image1)
image2 = imadjust (image1, [], [], 0.5);
subplot (3,2,2), imshow(image2)
subplot (3,2,2), imhist(image1)
subplot (3,2,1), imshow(image1)
subplot (3,2,2), imhist(image1)
subplot (3,2,3), imshow(image2)
subplot (3,2,4), imhist(image2)
image3 = histeq(image1);
subplot (3,2,5), imhist(image3)
subplot (3,2,6), imhist(image3)
subplot (3,2,5), imshow(image3)