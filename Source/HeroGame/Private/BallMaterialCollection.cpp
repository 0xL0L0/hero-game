// Fill out your copyright notice in the Description page of Project Settings.


#include "BallMaterialCollection.h"

UBallMaterialData* UBallMaterialCollection::GetBallMaterial(const TEnumAsByte<EBallMaterialType>& materialType)
{
	return BallMaterialMap.FindRef(materialType);
}
