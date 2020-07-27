if which python > /dev/null 2>&1;
then
    python scripts/build.py
else
    echo "Python does not appear to be installed, looks like you'll have to compile manually."
fi


