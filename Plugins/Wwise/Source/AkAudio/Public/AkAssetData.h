#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AkAssetData.generated.h"

UCLASS(Blueprintable)
class AKAUDIO_API UAkAssetData : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 CachedHash;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString BankLanguage;
    
    UAkAssetData();
};

