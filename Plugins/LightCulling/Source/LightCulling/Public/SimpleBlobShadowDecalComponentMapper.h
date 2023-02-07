#pragma once
#include "CoreMinimal.h"
#include "SimpleBlobShadowDecalComponentEntry.h"
#include "SimpleBlobShadowDecalComponentMapper.generated.h"

USTRUCT(BlueprintType)
struct FSimpleBlobShadowDecalComponentMapper {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSimpleBlobShadowDecalComponentEntry> Entries;
    
    LIGHTCULLING_API FSimpleBlobShadowDecalComponentMapper();
};

