#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LocDirectHttpService.generated.h"

UCLASS(Blueprintable)
class AVALOCDIRECT_API ULocDirectHttpService : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LocDirectAPI_Url;
    
public:
    ULocDirectHttpService();
};

