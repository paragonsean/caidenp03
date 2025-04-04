binaryImage = imread("fingerprint.tif");
sq = ones(3,3);
dilatedImage = imdilate(binaryImage, sq);
erodedImage = imerode(binaryImage, sq);
openImage = imopen(binaryImage,sq);
closeImage = imclose(binaryImage,sq);
subplot(2,3,1),imshow(binaryImage);
title original
subplot(2,3,2),imshow(dilatedImage);
title dilated
subplot(2,3,3),imshow(erodedImage);
title eroded
subplot(2,3,4),imshow(openImage);
title open
subplot(2,3,5),imshow(closeImage);
title close
