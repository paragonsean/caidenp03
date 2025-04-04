InputImage = imread("blood.tif");
Isobel = edge(InputImage, "sobel");
IRoberts = edge(InputImage, "roberts");
Iprewitt = edge(InputImage, "prewitt");
Icanny = edge(InputImage, "canny");
Ilog = edge(InputImage, "log");
subplot(2,3,1), imshow(InputImage);
title original
subplot(2,3,2), imshow(Isobel);
title sobel
subplot(2,3,3), imshow(IRoberts);
title roberts
subplot(2,3,4), imshow(Iprewitt);
title prewitt
subplot(2,3,5), imshow(Icanny);
title canny
subplot(2,3,6), imshow(Ilog);
title log
