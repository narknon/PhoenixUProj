#pragma once
#include "CoreMinimal.h"
#include "WorldObjectReference.generated.h"

class UObject;
class UWorld;

USTRUCT(BlueprintType)
struct UTILITIESRUNTIME_API FWorldObjectReference {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ObjectReferenceString_NoMarkup;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UObject> CachedObjectPtr;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UWorld> CachedForWorld;
    
public:
    FWorldObjectReference();
};

