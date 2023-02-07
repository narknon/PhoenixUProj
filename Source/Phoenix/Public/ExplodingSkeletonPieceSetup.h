#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ExplodingSkeletonSetup.h"
#include "ExplodingSkeletonPieceSetup.generated.h"

UCLASS(Blueprintable)
class UExplodingSkeletonPieceSetup : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FExplodingSkeletonSetup Pieces;
    
    UExplodingSkeletonPieceSetup();
};

