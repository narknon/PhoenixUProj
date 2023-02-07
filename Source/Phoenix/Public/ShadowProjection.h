#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ShadowProjection.generated.h"

class UAkAudioEvent;
class UAnimSequence;
class USkeletalMesh;

UCLASS(Blueprintable)
class UShadowProjection : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkeletalMesh* SkeletalMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequence* Animation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAkAudioEvent* AudioEvent;
    
    UShadowProjection();
};

