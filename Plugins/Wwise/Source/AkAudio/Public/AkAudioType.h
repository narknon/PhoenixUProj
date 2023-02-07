#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AkAudioType.generated.h"

UCLASS(Blueprintable)
class AKAUDIO_API UAkAudioType : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(AssetRegistrySearchable, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 ShortID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UObject*> UserData;
    
    UAkAudioType();
};

