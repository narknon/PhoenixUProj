#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "AnimNotify_SharedAkEvent.generated.h"

class UAkAudioEvent;
class USkeletalMesh;

UCLASS(Blueprintable, CollapseCategories)
class PHOENIX_API UAnimNotify_SharedAkEvent : public UAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFollow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SocketName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<USkeletalMesh*, UAkAudioEvent*> SharedAkEvents;
    
    UAnimNotify_SharedAkEvent();
};

