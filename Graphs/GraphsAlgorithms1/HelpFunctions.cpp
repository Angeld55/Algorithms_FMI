//help functions
void setAllTo(bool* arr, int len, bool value)
{
	for (int i = 0; i < len; i++)
		arr[i] = value;
}
bool allTrue(bool* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (!arr[i])
			return false;
	}
	return true;
}